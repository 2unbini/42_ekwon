#!/usr/bin/ruby -w

def sort_data
	data = [
	['Frank', 33],
	['Stacy', 15],
	['Juan' , 24],
	['Dom' , 32],
	['Steve', 24],
	['Jill' , 24]
	]
	data = data.sort_by{|x,y| x }
	data = data.sort_by{|x,y| y }
	return (data)
end

def print_name(data)
	data.each {|i| puts i[0]}
end

print_name(sort_data)