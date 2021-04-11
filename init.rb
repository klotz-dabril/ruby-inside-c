#
# init.rb
#
#

module MyModule
  def self.work_in_ruby
    work_in_c
    puts "Look, I'm working in ruby!"
  end

  module Inner
    def self.return_true
      true
    end
  end
end
