; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let (($x386964 (= arg0_7 (_ bv0 32))))
(let ((?x335 (ite $x386964 (_ bv0 32) (_ bv1 32))))
(let ((?x383043 (ite $x386964 (_ bv1 32) (_ bv0 32))))
(let ((?x386342 (bvmul (_ bv4294967295 32) ?x383043)))
(let ((?x386819 (bvadd ?x386342 ?x335)))
(and (distinct ?x386819 (_ bv0 32)) true)))))))
(check-sat)
