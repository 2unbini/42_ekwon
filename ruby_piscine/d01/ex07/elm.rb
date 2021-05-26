#!/usr/bin/ruby -w

def data_parsing
	array = Array.new
	File.new("periodic_table.txt", "r").each_line do |line|
		data = line.split('\n')
		table = Hash.new
		name, info = data[0].split(" = ")
		table.store("name", name)
		info.split(',').each do |pair|
			key, value = pair.split(':').map(&:strip)
			table.store(key, value)
		end
		array.push(table)
	end
	return array
end

def make_table(array, o_file)
	o_file.puts "<table>
	<tr>"
	i = 0
	array.each do |elem|
		if i == 18
			i = 0
			o_file.puts "</tr>
			<tr>"
		end
		if elem["position"] === i.to_s
			o_file.puts "<td style=\"border: 1px solid black; padding:10px\">
				<h4>#{elem["name"]}</h4>
				<ul>
					<li>#{elem["number"]}</li>
					<li>#{elem["small"]}</li>
					<li>#{elem["molar"]}</li>
					<li>#{elem["electron"]} electron</li>
				</ul>
			</td>"
			i += 1
		else
			o_file.puts "<td></td>"
			i += 1
			redo
		end
	end
	o_file.puts "</tr>
	</table>"
end

def make_css(array, o_file)
	o_file.puts "	<style>
	table {
		border: 1px solid black;
		border-collapse: collapse;
		margin: 0 auto;
		width: 100%;
	}
	td,
	tr{
		border: 1px solid black;
		padding : 10px;
		text-align: center;
		width : 5%
	}
	ul {
		padding : 0px;
	}
	li {
		list-style: none;
	}
	</style>
	"
end

def make_s_html(array, o_file)
	o_file.puts "<!DOCTYPE html>
	<html lang=\"en\">
	<head>
		<meta charset=\"UTF-8\">
		<title>Document</title>"
	make_css(array, o_file)
	o_file.puts "	</head>
	<body>
	"
end

def make_e_html(array, o_file)
	o_file.puts "</body>
	</html>
	"
end

def get_result
	array = data_parsing
	o_file = File.new("periodic_table.html", "w")
	make_s_html(array, o_file)
	make_table(array, o_file)
	make_e_html(array, o_file)
end

get_result()