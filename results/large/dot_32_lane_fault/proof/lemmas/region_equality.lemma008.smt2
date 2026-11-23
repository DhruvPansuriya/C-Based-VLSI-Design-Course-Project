; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x12310 (bvmul arg0_6 arg1_7)))
(let ((?x15743 (bvmul (_ bv4294967295 32) ?x12310)))
(let ((?x7119 (bvmul arg0_7 arg1_7)))
(let ((?x9277 (bvadd ?x7119 ?x15743)))
(and (distinct ?x9277 (_ bv0 32)) true))))))
(check-sat)
