; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_37 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg1_44 () (_ BitVec 32))
(assert
 (let ((?x73078 (bvmul arg0_5 arg1_37)))
(let ((?x46 (bvmul (_ bv4294967295 32) ?x73078)))
(let ((?x63626 (bvmul arg0_5 arg1_44)))
(let ((?x72113 (bvadd ?x63626 ?x46)))
(and (distinct ?x72113 (_ bv0 32)) true))))))
(check-sat)
