Parsepples, a Parslet-like parser for C++
=========================================
So yeah, while digging down on parsers I think writing something cool would be a good thing
to make some experience, it's been some time since I last wrote something in C++, so here we go.

As the title says, Parsepples is inspired by [Parslet](http://kschiess.github.com/parslet/),
a really really cool parsing tool for Ruby.

This stuff will be using C++0x, because I didn't try to use it yet, so this is a good chance to
learn some new stuff :)

Design choices
--------------
In C++ memory management becomes a problem, so I choose to leave all the memory management for
parsing results and whatever to the parser **Context**. This **Context** has a cache that keeps track
of all the **Result** objects, in this way you can parse and use the objects without worrying of what
to delete and what not. Keep in mind that said cache is destroyed when an **Atoms::Base** derived class
gets destroyed, this includes the parser itself, which means that if you instantiate a Parser, parse
something and want to keep using the results you have to call the clone method on the Result object,
because the results are destroyed after the Source or the Parser are destroyed.

If you use a Transform with the Parser you don't have to make clones and whatever, because the apply
method of the transformer returns an already cloned and usable Result that **YOU** have to delete
when you're done with it. Again, remember that destroying the parent of a Result (if it's an Hash or
an Array) destroys all the children. If you just use the String values you won't have this problems.
