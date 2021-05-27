#!/usr/bin/ruby -w

#lastline = 0
#a = File.new("test.txt")
#a.each do
#	lastline = $.
#end
#puts a
#string = a.read
#puts string.class
#arr = string.split("\n")
#puts arr
#puts arr[lastline - 1]



a = File.new("test.txt")
string = a.read()
arr = string.split("\n")
lastline = arr.count()

data = "my name is\ngunwoo.\n"
until !(arr[lastline - 1] == "")
	lastline -= 1
end
arr.delete(lastline - 1)
arr[lastline - 1] = data
arr[lastline] = "</body>"

string = arr.join("\n")
File.write(a, string)