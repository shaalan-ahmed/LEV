create_folder_and_files() {
  local folder_name="$1"

  if [ -d "$folder_name" ]; then
    echo "Class '$folder_name' already exists."
    return 1
  fi

  mkdir -p "../Classes/$folder_name"

  touch "../Classes/$folder_name/$folder_name.h"
  echo "#pragma once" > "../Classes/$folder_name/$folder_name.h"

  touch "../Classes/$folder_name/$folder_name.cpp"
  echo "#include  \"$folder_name.h\"" > "../Classes/$folder_name/$folder_name.cpp"
}

folder_name="${1:-}"

if [ -z "$folder_name" ]; then
  echo "Class name required"
  exit 1
fi

create_folder_and_files "$folder_name"
