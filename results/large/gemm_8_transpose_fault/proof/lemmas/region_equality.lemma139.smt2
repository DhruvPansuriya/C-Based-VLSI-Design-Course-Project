; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_30 () (_ BitVec 32))
(declare-fun arg0_22 () (_ BitVec 32))
(declare-fun arg1_51 () (_ BitVec 32))
(assert
 (let ((?x72932 (bvmul arg0_22 arg1_30)))
(let ((?x71406 (bvmul (_ bv4294967295 32) ?x72932)))
(let ((?x63317 (bvmul arg0_22 arg1_51)))
(let ((?x55185 (bvadd ?x63317 ?x71406)))
(and (distinct ?x55185 (_ bv0 32)) true))))))
(check-sat)
