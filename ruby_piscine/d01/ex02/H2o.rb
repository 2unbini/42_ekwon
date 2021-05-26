#!/usr/bin/ruby -w

def make_hash
	data = [['Caleb' , 24],
		['Calixte' , 84],
		['Calliste', 65],
		['Calvin' , 12],
		['Cameron' , 54],
		['Camil' , 32],
		['Camille' , 5],
		['Can' , 52],
		['Caner' , 56],
		['Cantin' , 4],
		['Carl' , 1],
		['Carlito' , 23],
		['Carlo' , 19],
		['Carlos' , 26],
		['Carter' , 54],
		['Casey' , 2]]
	data_hash = data.map(&:reverse).to_h
	return data_hash
end

def get_result(data_hash)
	data_hash.each do |k, v|
	puts "#{k} : #{v}"
	end
end

get_result(make_hash)