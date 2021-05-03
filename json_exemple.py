import json

# a Python object (dict):
x = {
  "name": "John",
  "age": 30,
  "city": "New York"
}

# convert into JSON:
aJsonString = json.dumps(x)

# the result is a JSON string:
print(aJsonString)

#get the name
aJsonObj = json.loads(aJsonString);
print(aJsonObj["age"])
