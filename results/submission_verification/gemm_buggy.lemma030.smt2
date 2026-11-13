; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x121 (bvmul arg0_8 arg1_4)))
(let ((?x21763 (bvmul (_ bv4294967295 32) ?x121)))
(let ((?x204 (bvmul arg0_8 arg1_1)))
(let ((?x8072 (bvadd ?x204 ?x21763)))
(and (distinct ?x8072 (_ bv0 32)) true))))))
(check-sat)
