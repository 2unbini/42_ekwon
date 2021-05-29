# frozen_string_literal: true

require "test_helper"
require "deepthought"

class DeepthoughtTest < Minitest::Test
  def setup
	@deepthought = Deepthought.new()
  end

  def test_respond
	assert_equal "42", @deepthought.respond("The Ultimate Question of Life, the Universe and Everything")
	assert_equal "Mmmm i'm bored", @deepthought.respond("Hello world")
  end
end
