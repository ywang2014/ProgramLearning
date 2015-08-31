#ÅÅĞò
manager<-c(1,2,3,4,5)
date<-c("10/24/08","10/28/08","10/01/08","10/12/08","05/01/09")
country<-c("US","US","UK","China","UK")
gender<-c("M","F","F","M","F")
age<-c(32,45,25,23,99)
q1<-c(5,3,3,2,1)
q2<-c(4,5,4,4,5)
q3<-c(2,4,3,4,3)
q4<-c(5,3,3,NA,2)
q5<-c(5,5,3,3,NA)
leadership<-data.frame(manager,date,country,gender,age,q1,q2,q3,q4,q5,stringsAsFactors=FALSE)
leadership$agecat[leadership$age>75]<-"Elder"
leadership$agecat[leadership$age>=55 &leadership$age<=75]<-"Middle Aged"
leadership$agecat[leadership$age<55]<-"Young"
leadership$date<-as.Date(leadership$date,"%m/%d/%y")
newdata<-leadership[order(leadership$gender),]
newdata



#ÉıĞò
attach(leadership)
newdata<-leadership[order(gender,age),]
detach(leadership)
newdata



#½µĞò
attach(leadership)
newdata<-leadership[order(gender,-age),]
detach(leadership)
newdata

##################order()  data[order(),] ¿É¶àÁĞÅÅĞòdata[order(,),]