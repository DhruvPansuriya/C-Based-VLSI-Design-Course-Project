; benchmark generated from python API
(set-info :status unknown)
(assert
 (let (($x42 (and (distinct (_ bv0 32) (_ bv0 32)) true)))
(let (($x50 (or $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42 $x42)))
(let (($x53 (and true true $x50)))
(or $x53)))))
(check-sat)
