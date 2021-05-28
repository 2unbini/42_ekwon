#!/usr/bin/ruby -w

class Elem
	attr_reader :tag, :content, :tag_type, :opt

	def initialize (*args)
		@tag = args[0]
		@content = Array.new()
		@opt = Hash.new()
		if args[1]
			args[1].class == Text ? @content = args[1] : @content.push(args[1])
		end
		if args[2] == "simple"
			@tag_type = "simple"
		else
			@tag_type = "double"
		end
		if args[3].class == Hash
			@opt = args[3]
		end
	end

	def add_content(*arr)
		arr.each { |x| @content.push(x) }
	end

	def to_s
		result = "<#{@tag}"
		@opt.each {|k, v| result += " #{k}='#{v}'"}
		if @tag_type == "simple"
			if @content.class == Array
				result += @content.join
			elsif @content.class == Text
				result += @content.string
			end
			result += " />"
		else
			result += ">"
			if @content.class == Array
				result += @content.join
			elsif @content.class == Text
				result += @content.string
			end
			result += "</#{@tag}>"
		end
		result.gsub!("><", ">\n<")
		return result
	end
end

class Text
	attr_reader :string

	def initialize (string)
		@string = string
	end
end

if $PROGRAM_NAME == __FILE__
	html = Elem.new('html')
	head = Elem.new('head')
	body = Elem.new('body')
	title = Elem.new('title', Text.new("blah blah"))
	h1 = Elem.new('h1', Text.new("This is header one"))
	img = Elem.new('img', '', 'simple',{'src':'http://i.imgur.com/pfp3T.jpg'})
	head.add_content(title)
	body.add_content([h1, img])
	html.add_content([head, body])
	puts html
end