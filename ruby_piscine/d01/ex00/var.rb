#!/usr/bin/ruby -w

def my_var
	a = 10
	b = "10"
	c = nil
	d = 10.0
	puts "my variables :"
	puts "	a contains: #{a} and is a type: #{a.class}"
	puts "	b contains: #{b} and is a type: #{b.class}"
	print "	c contains: ", c.inspect, " and is a type: #{c.class}\n"
	puts "	d contains: #{d} and is a type: #{d.class}"
end

my_var()