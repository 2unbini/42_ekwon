#!/usr/bin/ruby -w

def get_tluser
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
	city = ARGV
	if city.count() != 1
		return
	end
	if capitals_cities.value?(city[0]) == false
		puts "Unknown capital city"
		return
	end
	return puts states.key(capitals_cities.key(city[0]))
end

get_tluser()