
#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Введите: кол-во паролейб длина паролей"
  exit 1
fi

a=$1
b=$2

generate_password() {
  tr -dc 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789' </dev/urandom | head -c "$b"
  echo
}

for ((i=1; i<=a; i++)); do
  echo "Пароль $i: $(generate_password)"
done

