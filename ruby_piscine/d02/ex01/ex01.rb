#!/usr/bin/ruby -w

class Html
	attr_reader :name

	def initialize(name)
		@page_name = name
		if File.file?("#{@page_name}.html")
			raise RuntimeError, "A file named #{name}.html already exist!"
			return
		end
		head()
	end

	def head
		pname = @page_name + ".html"
		@ofile = File.new(pname, "w")
		@contents = "<!DOCTYPE html>\n<html>\n<head>\n<title>#{@page_name}</title>\n</head>\n"
	end

	def dump(string)
		if @contents.include? "</body>\n"
			raise RuntimeError, "Body has already been closed in #{@page_name}.html."
			return
		end
		if !(@contents.include? "<body>\n")
			@contents += "<body>\n"
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
	end
end

if $PROGRAM_NAME == __FILE__
	a = Html.new("test")
	10.times{|x| a.dump("titi_number#{x}")}
	a.finish
end