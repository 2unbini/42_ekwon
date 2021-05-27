#!/usr/bin/ruby -w

class Html
	attr_reader :name

	def initialize(name)
		@page_name = name
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
		@contents += "<p>#{string}</p>\n"
	end

	def finish
		@contents += "</body>\n</html>\n"
		@ofile.write(@contents)
	end
end

if $PROGRAM_NAME == __FILE__
	a = Html.new("test")
	10.times{|x| a.dump("titi_number#{x}")}
	a.finish
end