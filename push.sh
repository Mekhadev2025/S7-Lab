#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 'commit message'"
    exit 1
fi

commit_message="$1"

cd . || exit

git add .

git commit -m "$commit_message"

git push origin master

if [ $? -eq 0 ]; then
    echo "Changes pushed successfully!"
else
    echo "Failed to push changes."
fi