class Dog:
    def __init__(self, name, month, day, year, speakText):
        self.name =name
        self.month=month
        self.day =day
        self.year =year
        self.speakText=sepeakText

        def speak(self):
            return self.speakText
        
        def getName(self):
            return seld.name

        def birthDate(self):
            return str(self.month) + "/" +str(self.day) +"/"+str(self.year)

        def changeBark(seld,bark):
            self.speakText =bark

        def __add__(self,otherDog):
            return Dog("Puppy of"+ self.name + " and " +otherDog.name, \
                    self.month, self.day,self.year +1,\
                    self.speakText + otherDog.speakTest)

def main():
    doyDog =dog("Mesa",5,15,2004,"WOOF")
    girlDog =Dog("Sequoia",5,6,2004,"barkbark")
    print(boyDog.speak())
    print(girlDog.speak())
    print(boyDog.birthDate())
    print(girlDog.birthDate())
    boyDog.changeBark("woofywoofy")
    print(boyDog.speak())
    puppy=boyDog +girlDog
    print(puppy.speak())
    print(puppy.getName())
    print(puppy.birthDate())

if __name__ == "__main__":
    main()
