def takeInput():
    import pandas as pd
    data = pd.read_csv("res.csv")
    date = input("Enter The Date in DD/MM/YYYY format\n")
    memberData = list(data['Member'])
    # print(memberData)
    present = []
    flag = True
    while flag:
        inputs = list(map(str,input("Enter The First Names Separated by a Single Space For People With Same Name Write The First Letter Of Surname ex : Mushan Khan -> MushanK\n").split()))
        misSpelled = []
        for member in inputs:
            if member not in memberData:
                misSpelled.append(member)
                print(f"Added {member} to Mispelled")
            else:
                if member not in present:
                    present.append(member)
                print(f"Added {member} to Present")
            inputs.remove(member)
        if len(misSpelled) == 0:
            print(present)
            print("Continue??? Y or N")
            f = input().lower()
            if f == 'y':
                flag = False
        else:
            print("Enter The Spelling Correctly")
            print(misSpelled)
    return present
presenty = takeInput()