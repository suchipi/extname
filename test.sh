#!/usr/bin/env sh
set -x

# expected output is in comments between lines

./extname
# usage: extname [options] <string>
# options:
#   -f/--full: show full extension (more than one dot)
./extname -h
# usage: extname [options] <string>
# options:
#   -f/--full: show full extension (more than one dot)
./extname --help
# usage: extname [options] <string>
# options:
#   -f/--full: show full extension (more than one dot)
./extname something.ts
# .ts
./extname -f something.ts
# .ts
./extname --full something.ts
# .ts
./extname Makefile
# 
./extname -f Makefile
# 
./extname --full Makefile
# 
./extname something.d.ts
# .ts
./extname -f something.d.ts
# .d.ts
./extname --full something.d.ts
# .d.ts
./extname ./.git/hooks/commit-msg.sample
# .sample
./extname -f ./.git/hooks/commit-msg.sample
# .sample
./extname --full ./.git/hooks/commit-msg.sample
# .sample
