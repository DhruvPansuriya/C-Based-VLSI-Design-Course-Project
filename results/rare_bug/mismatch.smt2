; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0 () (_ BitVec 32))
(assert
 (let (($x13 (= arg0 (_ bv3735928559 32))))
(let (($x10 (not $x13)))
(let (($x11 (and true $x10)))
(let (($x20 (and true $x11 (or (and (distinct (_ bv0 32) (_ bv0 32)) true)))))
(let (($x9 (and true $x13)))
(let (($x25 (and true $x9 (or (and (distinct (_ bv4294967295 32) (_ bv0 32)) true)))))
(or $x25 $x20))))))))
(check-sat)
