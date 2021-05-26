#!/usr/bin/ruby  -w

def file_open
	file = File.new("numbers.txt")
	return file
end

def file_read
	file = file_open()
	data = file.read
	file.close
	return data
end

def data_split
	data = file_read()
	data = data.split(",\n")
	return data
end

def data_convert
	data = data_split()
	data = data.map(&:to_i)
	data = data.map{|a| a.to_i}
	return data
end

def data_sort
	data = data_convert()
	data = data.sort
	return data
end

def get_result
	data = data_sort()
	puts data
end

get_result()