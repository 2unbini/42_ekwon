#!/usr/bin/ruby -w

class Elem
	attr_reader :tag, :content, :tag_type, :opt

	def initialize(*args)
		if args[0].class == Array
			@content.push(args[0])
		else
			@tag = args[0]
		end
		@content = Array.new()
		@opt = Hash.new()
		if args[1].class == Text
			@content = args[1]
		elsif args[1].class == Array
			args[1].each { |x| @content.push(x) }
		elsif args[1].class != NilClass
			@content = args[1]
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
			elsif @content != nil
				result += @content
			end
			result += " />"
		else
			result += ">"
			if @content.class == Array
				result += @content.join
			elsif @content.class == Text
				result += @content.string
			elsif @content != nil
				result += @content
			end
			result += "</#{@tag}>"
		end
		result.gsub!("><", ">\n<")
		return result
	end
end

class Text
	attr_reader :string

	def initialize(string)
		@string = string
	end
end

class Html < Elem
	def initialize(*args)
		super("Html", args[0], 'double', args[1])
	end
end

class Head < Elem
	def initialize(*args)
		super("Head", args[0], 'double', args[1])
	end
end

class Body < Elem
	def initialize(*args)
		super("Body", args[0], 'double', args[1])
	end
end

class Title < Elem
	def initialize(*args)
		super("Title", args[0], 'double', args[1])
	end
end

class Meta < Elem
	def initialize(*args)
		super("Meta", args[0], 'simple', args[1])
	end
end

class Img < Elem
	def initialize(*args)
		super("Img", args[0], 'simple', args[1])
	end
end

class Table < Elem
	def initialize(*args)
		super("Table", args[0], 'double', args[1])
	end
end

class Th < Elem
	def initialize(*args)
		super("Th", args[0], 'double', args[1])
	end
end

class Tr < Elem
	def initialize(*args)
		super("Tr", args[0], 'double', args[1])
	end
end

class Td < Elem
	def initialize(*args)
		super("Td", args[0], 'double', args[1])
	end
end

class Ul < Elem
	def initialize(*args)
		super("Ul", args[0], 'double', args[1])
	end
end

class Ol < Elem
	def initialize(*args)
		super("Ol", args[0], 'double', args[1])
	end
end

class Li < Elem
	def initialize(*args)
		super("Li", args[0], 'double', args[1])
	end
end

class H1 < Elem
	def initialize(*args)
		super("H1", args[0], 'double', args[1])
	end
end

class H2 < Elem
	def initialize(*args)
		super("H2", args[0], 'double', args[1])
	end
end

class P < Elem
	def initialize(*args)
		super("P", args[0], 'double', args[1])
	end
end

class Div < Elem
	def initialize(*args)
		super("Div", args[0], 'double', args[1])
	end
end

class Span < Elem
	def initialize(*args)
		super("Span", args[0], 'double', args[1])
	end
end

class Hr < Elem
	def initialize(*args)
		super("Hr", args[0], 'simple', args[1])
	end
end

class Br < Elem
	def initialize(*args)
		super("Br", args[0], 'simple', args[1])
	end
end

if $PROGRAM_NAME == __FILE__
	puts H1.new("Oh no, not again!")
	#puts Html.new([Head.new([Title.new("Hello ground!")]),
	#Body.new([H1.new("Oh no, not again!"),
	#Img.new([], {'src':'http://i.imgur.com/pfp3T.jpg'}) ]) ])
end