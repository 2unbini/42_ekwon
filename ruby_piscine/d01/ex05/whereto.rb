#!/usr/bin/ruby -w

def get_result
	states = {
	"Oregon" => "OR",
	"Alabama" => "AL",
	"New Jersey" => "NJ",
	"Colorado" => "CO"
	}
	capitals_cities = {
	"OR" => "Salem",
	"AL" => "Montgomery",
	"NJ" => "Trenton",
	"CO" => "Denver"
	}
	str = ARGV
	if str.count() != 1
		return
	end
	arr = str[0].split(",")
	arr.each do |x|
		x = x.strip
		flag = 0
		next if x.casecmp("") == 0
		states.each do |k, v|
			if x.casecmp(k) == 0
				flag += 1
				print "#{capitals_cities[v]} is the capital of #{k} (akr: #{v})\r\n"
				break
			elsif x.casecmp(v) == 0
				flag += 2
				print "#{capitals_cities[v]} is the capital of #{k} (akr: #{v})\r\n"
				break
			else
				next
			end
		end
		next if flag == 2
		capitals_cities.each do |k, v|
			if x.casecmp(k) == 0 || x.casecmp(v) == 0
				flag += 1
				print "#{v} is the capital of #{states.key(k)} (akr: #{k})\r\n"
				break
			else
				next
			end
		end
		if flag == 0
			print "#{x.strip} is neither a capital city nor a state\r\n"
		end
	end
end

get_result()