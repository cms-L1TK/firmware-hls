####################
# Common Tcl tools #
####################

# Copied from
# https://wiki.tcl-lang.org/page/file+link#af880575babcfc1e542f7382331afcbc0de2f3f8fc4cdf4eb4248fb80bccff42
# Allows for broken links and overwriting of existing links.
proc linkCreate {target linkname} {
    exec ln -sf $target $linkname
    return
}
