import pandas as pd
def sortWithCriteria(arr,low,high,criteria):
    if low < high:
        mid = (high + low)//2
        sortWithCriteria(arr,mid+1,high,criteria)
        sortWithCriteria(arr,low,mid,criteria)
        merge(arr,low,mid,high,criteria)

def merge(arr,low,mid,high,criteria):
    b = len(arr)*[0]
    i = low
    k = low
    j = mid + 1
    if criteria == "W":
        while i <= mid and j <= high:
            if arr[i]['compressionRatio'] < arr[j]['compressionRatio']:
                b[k] = arr[i]
                i+=1
                k+=1
            else:
                b[k] = arr[j]
                j+=1
                k+=1
        while i <= mid:
            b[k] = arr[i]
            k+=1
            i+=1
        while j <= high:
            b[k] = arr[j]
            j+=1
            k+=1
        for i in range(low,high+1):
            arr[i] = b[i]
    if criteria == "P":
        while i <= mid and j <= high:
            if arr[i]['priority'] > arr[j]['priority']:
                b[k] = arr[i]
                i+=1
                k+=1
            else:
                b[k] = arr[j]
                j+=1
                k+=1
        while i <= mid:
            b[k] = arr[i]
            k+=1
            i+=1
        while j <= high:
            b[k] = arr[j]
            j+=1
            k+=1
        for i in range(low,high+1):
            arr[i] = b[i]
    if criteria == "R":
        while i <= mid and j <= high:
            if arr[i]['priority']/arr[i]['compressionRatio'] > arr[j]['priority']/arr[i]['compressionRatio']:
                b[k] = arr[i]
                i+=1
                k+=1
            else:
                b[k] = arr[j]
                j+=1
                k+=1
        while i <= mid:
            b[k] = arr[i]
            k+=1
            i+=1
        while j <= high:
            b[k] = arr[j]
            j+=1
            k+=1
        for i in range(low,high+1):
            arr[i] = b[i]

def knapSack(files,storage,criteria):
    weight = 0
    ptr = 0
    profit = 0
    res = []
    x = []
    if criteria == "R":
        sortWithCriteria(files,0,len(files)-1,"R")
    elif criteria == "W":
        sortWithCriteria(files,0,len(files)-1,"W")
    else:
        sortWithCriteria(files,0,len(files)-1,"P")
    while weight < storage:
        if files[ptr]['compressionRatio'] <= storage - weight:
            res.append(files[ptr])
            weight+= files[ptr]['compressionRatio']
            profit+= files[ptr]['priority']
            ptr+=1
            x.append(1)
        else:
            res.append(files[ptr])
            fraction =  (storage - weight) / files[ptr]['compressionRatio']
            weight+= files[ptr]['compressionRatio'] / fraction
            profit+= files[ptr]['priority']/fraction
            x.append(fraction)
    return {
        'res':res,
        'resx':x,
        'profit':profit
    }

files = [
    {
        "compressionRatio":2,
        "priority":5
    },
    {
        "compressionRatio":3,
        "priority":8
    },
    {
        "compressionRatio":8,
        "priority":10
    },
    {
        "compressionRatio":7,
        "priority":13
    },
    {
        "compressionRatio":6,
        "priority":4
    }
]

files = pd.read_csv('sample.csv')
cr = files['compressionRatio']
p = files['priority']
data = [
    {
            "compressionRatio":2,
            "priority":5
        },
    {
            "compressionRatio":3,
            "priority":8
        },
    {
            "compressionRatio":5,
            "priority":10
        },
    {
            "compressionRatio":7,
            "priority":13
        },
    
]

print("Select A Criteria :- ")
m = input("R - Ratio , W - Weight , P - Priority")
result = knapSack(data,7,m)
x = [0]*len(data)
for i in range(len(result['res'])):
    index = data.index(result['res'][i])
    x[index] = result['resx'][i]
print("The Given Data \n")
print(data)
print("\n\n Subset \n")
print(result['res'])
print(x)
print(result['profit'])