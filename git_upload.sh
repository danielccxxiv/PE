#!/bin/bash
git add -A
git rm */main --cache
git rm *.o --cache
git rm *.a --cache
git rm *.d --cache
git rm *.gch --cache
git rm */.sconsign.dblite --cache
git commit -m "0"
git push

