#-- sc_parser_test133.sc

regclass foo( float f1, double d2, bool b3, u7 i4,
              u14 i5, u12 i6, u67 i7, s1024 i8, s3 i9,
              s21 i10, s19 i11)
regclass bar( float f1, double d2, bool b3, u7 i4,
              u14 i5, u12 i6, u67 i7, s1024 i8, s3 i9,
              s21 i10, s19 i11)


def foo1(a b x){
  pipe p0{
    b = b + x
    a = b + x
  }
  pipe p1{
    a = a * x
  }
}

def foo1(a b x){
  pipe p0{
    x = b+x
    a = b+x
  }
  pipe p3{
    a = a/x
  }
}

