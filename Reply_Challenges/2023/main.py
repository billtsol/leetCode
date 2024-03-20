import random

# Open the file
with open("./01-chilling-cat.txt", "r") as file:
    # Read the content of the file
    lines = file.readlines()

# Parsing the first line to get C, R, S
C, r, S = map(int, lines[0].split())


# Parsing the second line as S values
S_values = list(map(int, lines[1].split()))

# Parsing each subsequent line into integers as a matrix of size C * R
matrix = []
for line in lines[2:]:
    row_values = list(map(str, line.split()))
    matrix.append(row_values)

# # Printing the S values and the matrix
# print("S values:", S_values)
# print("Matrix:")
# for row in matrix:
#     print(row)

# print(C,R,S)

# Using nested loops
star_indices = []
for i in range(len(matrix)):
    for j in range(len(matrix[i])):
        if matrix[i][j] == "*":
            star_indices.append((i, j))

S_values.sort(reverse=True)
solution = []

for i in S_values:
  temp_solution = []

  temp_moves = []

  # Start point
  rand_x = random.randint(0, r) # row
  rand_y = random.randint(0, C) # column

  while True:
    try:
      while ( int(matrix [rand_x][rand_y]) < 0 or matrix [rand_x][rand_y] == "10001"):
        rand_x = random.randint(0, r) # column
        rand_y = random.randint(0, C) # row

      break
    except:
      rand_x = random.randint(0, r) # row
      rand_y = random.randint(0, C) # column


  temp_solution.append(str(rand_x))
  temp_solution.append(" " + str(rand_y))

  # end of start point

  # Next Move
  s_length = i - 1

  last_value = None

  while ( s_length > 0):

    temp_y = (rand_y + 1 ) % C
    R = [ rand_x , temp_y , 'R']

    if rand_y - 1 < 0:
      L = [ rand_x , C - 1, 'L']
    else:
      L = [ rand_x , rand_y - 1, 'L']

    temp_x = (rand_x + 1 ) % r
    D = [ temp_x ,  rand_y, 'D']

    if rand_x - 1 < 0:
      T = [ r - 1, rand_y , 'T']
    else:
      T = [ rand_x - 1, rand_y, 'T']

    list_test = []

    if ( matrix[T[0]][T[1]] != "10001" and  ( T[0] , T[1] ) not in temp_moves  ):
      list_test.append((T, -10001 if matrix[T[0]][T[1]] == '*' else int(matrix[T[0]][T[1]])))

    if (matrix[D[0]][D[1]] != "10001" and ( D[0] , D[1] ) not in temp_moves):
      list_test.append((D, -10001 if matrix[D[0]][D[1]] == '*' else int(matrix[D[0]][D[1]])))

    if (matrix[L[0]][L[1]] != "10001" and ( L[0] , L[1] ) not in temp_moves):
      list_test.append( (L, -10001 if matrix[L[0]][L[1]] =='*' else  int(matrix[L[0]][L[1]])))

    if (matrix[R[0]][R[1]] != "10001" and ( R[0] , R[1] ) not in temp_moves):
      list_test.append( (R, -10001 if matrix[R[0]][R[1]] == '*' else int(matrix[R[0]][R[1]])))

    list_test.sort(key=lambda x: x[1], reverse=True)

    print(i)
    if (len(list_test) == 0):

      rand_x = temp_moves[len(temp_moves) - 2][0]
      rand_y = temp_moves[len(temp_moves) - 2][1]

      if len(temp_solution) > 0:
        temp_solution.pop()

      if last_value != None:
        pos_x = temp_moves[len(temp_moves) - 1][0]
        pos_y = temp_moves[len(temp_moves) - 1][1]
        matrix[pos_x][pos_y] = last_value

      s_length += 1
    else:

      if list_test[0][1] < 0:
        if list_test[len(list_test) - 1] == -10001:
          temp_solution.append(" " + list_test[3][2])
          temp_moves.append((rand_x, rand_y))

          star_index = random.randint(0,len(star_indices))

          rand_x = star_indices[star_index][0] # row
          rand_y = star_indices[star_index][1] # column

          temp_solution.append(str(rand_x))
          temp_solution.append(" " + str(rand_y))

        else:
          # All negative
          temp_solution.append(" " + list_test[0][0][2])
          temp_moves.append((rand_x, rand_y))

          last_value = matrix[rand_x][rand_y]
          matrix[rand_x][rand_y] = "10001"


          rand_x = list_test[0][0][0] # row
          rand_y =  list_test[0][0][1] # column
      else:

        temp_solution.append(" " + list_test[0][0][2])
        temp_moves.append((rand_x, rand_y))

        last_value = matrix[rand_x][rand_y]
        matrix[rand_x][rand_y] = "10001"

        rand_x = list_test[0][0][0] # row
        rand_y =  list_test[0][0][1] # column

      s_length -= 1

  matrix[rand_x][rand_y] = "10001"

  solution.append(temp_solution)


for i in solution:
  print(''.join(i))