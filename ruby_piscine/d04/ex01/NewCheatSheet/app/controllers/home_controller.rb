#ApplicationController is
class HomeController < ApplicationController

	def convention
		@title = "Convention"
	end

	def console
		@title = "Console"
	end

	def ruby
		@title = "Ruby"
	end

	def ruby_concepts
		@title = "Ruby-concepts"
	end

	def ruby_numbers
		@title = "Ruby-numbers"
	end

	def ruby_strings
		@title = "Ruby-strings"
	end

	def ruby_arrays
		@title = "Ruby-arrays"
	end

	def ruby_hashes
		@title = "Ruby-hashes"
	end

	def rails_folder_structure
		@title = "Rails-folder-structure"
	end

	def rails_commands
		@title = "Rails-commands"
	end

	def rails_erb
		@title = "Rails-erb"
	end

	def editor
		@title = "Editor"
	end

	def help
		@title = "Help"
	end
end
