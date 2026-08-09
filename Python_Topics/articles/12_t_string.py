# with prompt engineering into big picture, people needed to make templates
# but f-strings are injectible that we can actually execute code inside {}
# and they are evaluated as soon as interpreter gets at that line.

# t-strings expressions are not string, but Template object, where we can
# interpolate dictionaries as html attributes, many libs exist that use
# the t-strs for SQL Scripts.

# thus t-strings were made for sanitzing xml,yaml,html,json etc templates.
# since Python 3.14

name = "Python"
year = 2026

template = t"hello {name}, in year {year}."

print(template.strings)
print(template.interpolations)
print(template.values)
print(template)
