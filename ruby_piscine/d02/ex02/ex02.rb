#!/usr/bin/ruby -w

#Dup_file, Body_closed 라는 두 개의 클래스를 만들자
#각각은 StandardError 클래스를 상속받는다
#두 클래스는 show_state, correct, explain 메소드를 갖고
#show_state => 수정 전의 상태를 보여줌
#correct => raise 로 일어난 에러를 수정함
#explain => 수정 후의 상태를 보여줌
#있는 파일을 만드려고 하면, 코드는 Dup_file exception을 일으키고,
#이는 비슷한 파일들의 리스트를 전체 경로와 함께 보여줌
#파일 확장자 전에 .new 를 붙인다.
#</body> 태그 뒤에 무언가 쓰려고 하면, 코드는 Body_closed exception을 일으키고,
#이는 닫힌 바디 태그의 위치(줄 넘버)를 보여주고,
#해당 태그를 삭제한 뒤 텍스트를 넣고, 다시 바디 태그를 닫아준다.


class Html
	attr_reader :name

	def initialize(name)
		@page_name = name
		begin
			raise Dup_file, "A file named #{name}.html already exist!" if File.file?("#{@page_name}.html")
		rescue Dup_file
			derror = Dup_file.new(@page_name)
			derror.show_state()
			derror.correct()
			derror.explain()
		end
		head()
	end

	def head
		pname = @page_name + ".html"
		@ofile = File.new(pname, "w")
		@contents = "<!DOCTYPE html>\n<html>\n<head>\n<title>#{@page_name}</title>\n</head>\n"
	end

	def dump(string)
		if !(@contents.include? "<body>\n")
			@contents += "<body>\n"
		end
		begin
			raise Body_closed, "Body has already been closed in #{@page_name}.html." if @contents.include? "</body>\n"
		rescue Body_closed
			berror = Body_closed.new(@page_name)
			berror.show_state()
			berror.correct(string)
			berror.explain()
			return
		end
		@contents += "<p>#{string}</p>\n"
	end

	def finish
		if !(@contents.include? "<body>\n")
			raise RuntimeError, "There is no body tag in #{@page_name}.html."
			return
		elsif @contents.include? "</body>\n"
			raise RuntimeError, "#{@page_name}.html has already been closed."
			return
		else
			@contents += "</body>\n</html>\n"
		end
		@ofile.write(@contents)
		@ofile.close()
	end
end


class Dup_file < StandardError
	def initialize(filename)
		@filename = filename
	end

	def show_state
		@dir = Dir.getwd
		Dir.new(@dir).each do |x|
			if x.include? @filename
				puts "A file named #{@filename} was already there: #{@dir}/#{x}"
			end
		end
	end

	def correct
		until !(File.file?("#{@filename}.new.html"))
			@filename += ".new"
		end
		File.new("#{@filename}.new.html","w")
	end

	def explain
		puts "Appended .new in order to create requested file: #{@dir}/#{@filename}.new.html"
	end
end

class Body_closed < StandardError
	def initialize(filename)
		@filename = filename
	end

	def show_state
		puts "In #{@filename} body was closed :"
	end

	def correct(text)
		file = File.new("#{@filename}.html")
		arr = file.read().split("\n")
		# arr.index("</body>\n")
		@index = arr.index("</body>")
		arr.slice!(@index..)
		arr[@index] = "<p>#{text}</p>"
		arr[@index + 1] = "</body>"
		arr[@index + 2] = "</html>"
		File.write(file, arr.join("\n") + "\n")
		file.close
	end

	def explain
		puts "ln :#{@index + 2} </body> : text has been inserted and tag moved at the end of it."
	end
end

if $PROGRAM_NAME == __FILE__
	a = Html.new("test")
	10.times{|x| a.dump("titi_number#{x}")}
	a.finish
end