namespace Calc {
    void
    ne_(UNUSED_PARAM(unsigned traversal_number),
        UNUSED_PARAM(parse_direction_t direction),
        UNUSED_PARAM(parser_t *parser),
        UNUSED_PARAM(Node *v))
    {
        if (traversal_number == 1) {
            switch (direction) {
            case TOP_DOWN:
                break;

            case BOTTOM_UP:
                printf("\t\tNE\n");
                break;
            }
        }
    }
};
