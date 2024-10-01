#!/bin/bash

# Check if a commit message was provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 'commit message'"
    exit 1
fi

# Get the commit message from the argument
commit_message="$1"

# Navigate to your Git repository (change this path to your repository's path)
cd . || exit

# Add all changes
git add .

# Commit with the provided message
git commit -m "$commit_message"

# Push to the origin master branch
git push origin master

# Check if the push was successful
if [ $? -eq 0 ]; then
    echo "Changes pushed successfully!"
else
    echo "Failed to push changes."
fi