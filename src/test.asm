add al, -4(%rbp)
mov %al, -8(%rbp)

subroutine:
cmc
jump subroutine
