Rails.application.routes.draw do
  # For details on the DSL available within this file, see https://guides.rubyonrails.org/routing.html

  root "home#convention"
  get "/convention" => "home#convention"
  get "/console" => "home#console"
  get "/ruby" => "home#ruby"
  get "/ruby-concepts" => "home#ruby_concepts"
  get "/ruby-numbers" => "home#ruby_numbers"
  get "/ruby-strings" => "home#ruby_strings"
  get "/ruby-arrays" => "home#ruby_arrays"
  get "/ruby-hashes" => "home#ruby_hashes"
  get "/rails-folder-structure" => "home#rails_folder_structure"
  get "/rails-commands" => "home#rails_commands"
  get "/rails-erb" => "home#rails_erb"
  get "/editor" => "home#editor"
  get "/help" => "home#help"

end
