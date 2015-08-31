rankall <- function(outcome, num = "best")
{
        file <- "assign/rprog_data_ProgAssignment3-data/outcome-of-care-measures.csv"
        data <- read.csv(file);
        s_outcome <- c("heart attack", "heart failure", "pneumonia")
        if (outcome == s_outcome[1])
        {
                new_data <- data.frame(data[, 2], data[, 7], data[, 11])
        }
        else if (outcome == s_outcome[2])
        {
                new_data <- data.frame(data[, 2], data[, 7], data[, 17])
        }
        else if (outcome == s_outcome[3])
        {
                new_data <- data.frame(data[, 2], data[, 7], data[, 23])
        }
        else
        {
                return("invalid outcome")
        }
        new_data[, 3] <- as.numeric(new_data[, 3])
        state <- as.vector(new_data[, 2])
        state <- unique(state)
        state <- state[order(state)]
        name <- NULL
        sta <- NULL
        for (i in 1:length(state))
        {
                a <- new_data[, 2] == state[1]
                b <- subset(new_data, a)
                bad <- b[3] == "Not Available"
                data <- subset(b, !bad)
                data[, 2] <- as.numeric(data[, 2])
                data[, 1] <- as(data[, 1], "character")
                d <- data[order(data[,2]), ]
                if (num == "best")
                {
                        name <- c(name, d[1, 1])
                }
                else if (num == "worst")
                {
                        name <- c(name, d[nrow(d), 1])
                }
                else
                {
                        if (num > nrow(d))
                        {
                                name <- c(name, "<NA>")
                        }
                        else
                        {
                                name <- c(name, d[num, 1])
                        }
                }
        }
        data.frame(hospital=name, state=state)
}