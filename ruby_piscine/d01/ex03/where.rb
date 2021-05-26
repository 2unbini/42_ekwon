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
	state = ARGV
	if state[0] == "New" && state[1] == "Jersey"
		return puts capitals_cities[states["New Jersey"]]
	end
	if state.count() != 1
		return
	end
	if states.key?(state[0]) == false
		puts "Unknown state"
		return
	end
	return puts capitals_cities[states[state[0]]]
end

get_result()