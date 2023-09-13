# extname

command-line utility for finding the extension of a filename/filepath. the long-lost sister of `dirname` and `basename`

```sh
$ extname
usage: extname [options] <string>
options:
  -f/--full: show full extension (more than one dot)
$ extname something.ts
.ts
$ extname Makefile

$ extname something.d.ts
.ts
$ extname -f something.d.ts
.d.ts
$ extname ./.git/hooks/commit-msg.sample
.sample
```

Made by Lily Skye in December 2022

I release this work into the public domain

tests rely on [hopic](https://github.com/suchipi/hopic/releases/tag/0.1.0)
