best <- function(state, outcome)
{
        #olddir <- getwd();
        #setwd("");
        file <- "assign/rprog_data_ProgAssignment3-data/outcome-of-care-measures.csv"
        #outcome_data <- read.csv(file, colClasses = "character");
        outcome_data <- read.csv(file);
        #hospital_data <- read.csv("assign/rprog_data_ProgAssignment3-data/hospital-data.csv")
        s_outcome <- c("heart attack", "heart failure", "pneumonia")
        a <- outcome_data["State"] == state
        #b <- s_data[a]
        b <- subset(outcome_data, a)
        if (nrow(b) == 0)
        {
                return("invalid state")
        }
        if (outcome == s_outcome[1])
        {
                data <- data.frame(b[, 2], b[, 11])
        }
        else if (outcome == s_outcome[2])
        {
                data <- data.frame(b[, 2], b[, 17])
        }
        else if (outcome == s_outcome[3])
        {
                data <- data.frame(b[, 2], b[, 23])
        }
        bad <- data[,2] == "Not Available"
        data <- subset(data, bad)
        #data[, 2] <- as.numeric(data[, 2])
        #s <- unlist(data[2]) ##############
        #s <- as.vector(data[2])
        
        #c <- data[order(data[,2],data[,1]), ]
        c <- data[order(data[,2]), ]
        c[1, 1]
}
###student<-data.frame(ID=c(11,12,13),Name=c("Devin","Edward","Wenli"),Gender=c("M","M","F"),Birthdate=c("1984-12-29","1983-5-6","1986-8-8¡±))