#!/usr/bin/ruby -w

class Html
	attr_reader :name

	def initialize(name)
		@page_name = name
		head()
	end

	def file_out
		pname = @page_name + ".html"
		ofile = File.new(pname, "w")
		ofile.write(@contents)
	end

	def head
		@contents = "<!DOCTYPE html>\n<html>\n<head>\n<title>#{@page_name}</title>\n</head>\n"
	end

	def dump(string)
		if !(@contents.include? "<body>\n")
			@contents += "<body>\n"
		end
		@contents += "<p>#{string}</p>\n"
	end

	def finish
		@contents += "</body>\n"
		file_out()
	end
end

if $PROGRAM_NAME == __FILE__
	a = Html.new("test")
	10.times{|x| a.dump("titi_number#{x}")}
	a.finish
end