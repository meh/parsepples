require 'rake'
require 'rake/clean'

NAME    = 'parsepples'
VERSION = '0.0.1'

def name
  "#{NAME}.#{VERSION}"
end

CXX     = ENV['CXX'] || 'g++'
AR      = ENV['AR']  || 'ar'
CFLAGS  = "-Os -Wall -Wextra #{`pcre-config --cflags`.strip} -Iinclude" + " #{ENV['CFLAGS']}"
LDFLAGS = "#{`pcre-config --libs`.strip}" + " #{ENV['LDFLAGS']}"

if ENV['DEBUG']
  CFLAGS << ' -O0 -g3'
end

SOURCES = FileList['source/**/*.cpp']
OBJECTS = SOURCES.ext('o')

task :default => ["lib#{name}.so", "lib#{name}-static.a"]

rule '.o' => '.cpp' do |t|
  sh "#{CXX} #{CFLAGS} -fPIC -o #{t.name} -c #{t.source}"
end

file "lib#{name}.so" => OBJECTS do
  sh "#{CXX} #{CFLAGS} #{OBJECTS} -shared -Wl,-soname,lib#{name} -o lib#{name} #{LDFLAGS}"
end

file "lib#{name}-static.a" => OBJECTS do
  sh "#{AR} rcs lib#{name}-static.a #{OBJECTS}"
end
