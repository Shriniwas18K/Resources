class Player:
    num_players = 0
    def __init__(self):
        self.num_players+=1

p1=Player()
p2=Player()
print(Player.num_players) # 0
print(p1.num_players) # 1
print(p2.num_players) # 1 
# this output comes because here in every instance
# self.num_players = self.num_players + 1
# 1 assigned to instance object attribute self.num_players
# where class object attribute self.num_players is 0 as
# while initializing instance self.num_players in RHS doesnot
# exist so it is looked up in class __dict__
"""
python stores attributes of each object in dunder __dict__ attribute
and everything is object in python.It does lookup in order as
1) instance dunder __dict__
2) dunder __dict__ of class of the instance
3) dunder __dict__ of the classes in order of the __mro__ of the class of the instance
4) dunder __getattr__ and then descriptors searching
else AttributeError
"""
