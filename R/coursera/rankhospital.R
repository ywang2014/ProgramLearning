rankhospital <- function(state, outcome, num)
{
        file <- "assign/rprog_data_ProgAssignment3-data/outcome-of-care-measures.csv"
        outcome_data <- read.csv(file);
        s_outcome <- c("heart attack", "heart failure", "pneumonia")
        a <- outcome_data["State"] == state
        b <- subset(outcome_data, a)
        if (nrow(b) == 0)
        {
                stop("invalid state")
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
        else
        {
                stop("invalid outcome")
        }
        bad <- data[2] == "Not Available"
        data <- subset(data, !bad)
        data[, 2] <- as.numeric(data[, 2])
        c <- data[order(data[,2]), ]
        if (num == "best")
        {
                d <- as.character(c[1, 1])
        }
        else if (num == "worst")
        {
                d <- as.character(c[nrow(c), 1])
        }
        else
        {
                if (num > nrow(c))
                {
                        return(NA)
                }
                else
                {
                        d <- as.character(c[num, 1])
                }
        }
        d
}
# rankhospital("NY", "heart attak", 7)