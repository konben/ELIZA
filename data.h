#define END 0

/* Pronoun conjugations. 
 * Ordered as: subject, object */
char *conjugations[] = {
    "ARE", "AM",
    "WERE", "WAS",
    "YOUR", "MY",
    "YOU", "I",
    "I'VE", "YOU'VE",
    "I'M", "YOU'RE",
    "MYSELF", "YOURSELF",
    "AM", "ARE",
    "WAS", "WERE",
    "MY", "YOUR",
    "I", "YOU",
    "ME", "YOU",
    "YOU'VE", "I'VE",
    "YOU'RE", "I'M",
    "YOURSELF", "MYSELF",    
    END,
};

/* A mapping of keywords to their replies.
 * Ordered as: keyword, reply */
char *keyword_replies[] = {
    "COMPUTER", "AND YOU DON'T BELIEVE A COMPUTER CAN HELP YOU?",    
    "WHAT DO", "WELL, WHAT DO YOU THINK %s?",
    "WHAT", "WELL, WHAT DO YOU BELIEVE %s?",
    "I REALLY", "I SEE... STRONG FEELINGS, BUT WHY EXACTLY DO YOU %s?",
    "I", "AND WHY IS IT THAT YOU %s?",
    "CAN YOU", "DON'T YOU BELIEVE I CAN %s?",
    "WHY", "WELL, WHY DO YOU THINK THAT IS?",
    "FUCK", "LANGUAGE, PLEASE!",
    "F*CK", "LANGUAGE, PLEASE!",
    "HE", "AND WHAT DO YOU THINK ABOUT HIM, PERSONALLY?",
    "SHE", "AND WHAT DO YOU THINK ABOUT HER, PERSONALLY?", 
    "YOU", "THIS ISN'T ABOUT ME, ISN'T IT?",
    // TODO: Add more keywords.
    END,
};

/* I no keyword was found, use this reply.
   Maybe I will multiple default replies to choose from later, idk. */
char no_keyword[] = "CAN YOU ELABORATE ON THAT?";
