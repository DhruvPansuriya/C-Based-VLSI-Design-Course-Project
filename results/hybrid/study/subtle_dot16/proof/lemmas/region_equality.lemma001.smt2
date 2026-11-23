; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_11 () (_ BitVec 32))
(declare-fun arg0_10 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(assert
 (let ((?x303234 (bvmul arg0_10 arg1_11)))
(let ((?x331558 (bvmul (_ bv4294967295 32) ?x303234)))
(let ((?x349593 (bvmul arg0_11 arg1_11)))
(let ((?x304338 (bvadd ?x349593 ?x331558)))
(and (distinct ?x304338 (_ bv0 32)) true))))))
(check-sat)
