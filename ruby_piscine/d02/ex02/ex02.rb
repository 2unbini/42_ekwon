#!/usr/bin/ruby -w

class Html
	attr_reader :name

	def initialize(name)
		@page_name = name
		begin
			raise Dup_file.new(@page_name), "A file named #{name}.html already exist!" if File.file?("#{@page_name}.html")
		rescue => derror
			derror.show_state
			@page_name = derror.correct
			derror.explain
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
			raise Body_closed.new(@page_name), "Body has already been closed in #{@page_name}.html." if @contents.include? "</body>\n"
		rescue Body_closed => berror
			berror.show_state
			berror.correct(string)
			berror.explain
			rescue
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
		until !(File.file?("#{@filename}.html"))
			@filename += ".new"
		end
		@ofile = File.new("#{@filename}.html","w")
		@ofile.write("<!DOCTYPE html>\n<html>\n<head>\n<title>#{@filename}</title>\n</head>\n")
		return @filename
	end

	def explain
		puts "Appended .new in order to create requested file: #{@dir}/#{@filename}.html"
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
		@index = arr.index("</body>")
		arr.slice!(@index..)
		arr[@index] = "<p>#{text}</p>"
		arr[@index + 1] = "</body>"
		arr[@index + 2] = "</html>"
		File.write(file, arr.join("\n") + "\n")
		file.close
	end

	def explain
		puts "ln :#{@index + 3} </body> : text has been inserted and tag moved at the end of it."
	end
end

if $PROGRAM_NAME == __FILE__
	a = Html.new("test")
	a = Html.new("test")
	a.dump("A")
	a.dump("B")
	a.finish
	a.dump("C")
end