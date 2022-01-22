#!/bin/bash
# Ask the user for commit msg
echo 'All changes will be pushed to remote repo.'
read -p 'Enter Commit Message: ' msg
git add .
git commit -m "$msg"
git push
echo 'Done! Happy Coding'
