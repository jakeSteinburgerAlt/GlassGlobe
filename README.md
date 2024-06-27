# GlassGlobe
A basic web browser from scratch.

You may think that building a whole web browser, from HTML rendering to a JS engine, is an *incredibly* complex task. Well, you'd be correct. I'm not trying to build the next chromium here. To be perfectly honest, I barely know how a web browser works. As far as I know, it's just a DOM tree with some attributes than has a language just for dynamically changing that DOM tree, and it just graphically has to load that tree.

Point is, I have no idea what I'm doing. The reason for this is partly for fun, but also partly because my [hobby operating system](https://github.com/jakeSteinburger/SpecOS) is (very, very slowly) coming together, and once I port a networking stack and some graphics, I'd really love a web browser for it. However, it is, unfortunately not really binary compatible with anything, nor do I plan for it to be, and porting chromium is a pain in the ass. For this reason, I'm writing it myself.

This is a C++ project, because a project like this uses a lot of vectors which I don't get in C. Note that when I say "from scratch", I mean the HTML & CSS renderer. The JS engine I plan to try to use chromium's V8, but if I can't then I might try just write it myself. I'm not going to properly implement a frontend, just the app's backend, until I actually port to SpecOS. Until then, I might try make a basic GUI for it with GTK, but nothing complete because the ported version will use a custom widget/graphics library anyway.

GlassGlobe may not be complete for a *very* long time, mainly because it's a huge project (possibly even bigger than the whole operating system, but using V8 makes it easier) and because it's a side project with SpecOS being my main project. 

Until I have something useful, whether that be graphical or not, I will not write proper build or install instructions, since basically all I have is a small part of a DOM parser. This code is, to be honest, very badly written, so it may be difficult to contribute to. However, I try to write a decent amount of comments to make it partially understandable.

## Roadmap
- [ ] DOM parser
- [ ] CSS selector & style attribute editor
- [ ] V8 port to dynamically change DOM
- [ ] Graphics (not sure if it'll be gtk or custom first)
