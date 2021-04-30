
class Number:
  def __init__(this,rel):
    this._rel = rel


class Complex(Number):
  def __init__(this,rel,img):
    super().__init__(rel)
    this._img = img
    
  def toPrint(this):
    print(this._rel , this._img)


c1 = Complex(1,3)
c1.toPrint();
