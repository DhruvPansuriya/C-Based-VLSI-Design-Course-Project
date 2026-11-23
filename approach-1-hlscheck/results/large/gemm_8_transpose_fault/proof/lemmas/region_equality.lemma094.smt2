; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_44 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_37 () (_ BitVec 32))
(assert
 (let ((?x64100 (bvmul arg0_12 arg1_44)))
(let ((?x69262 (bvmul (_ bv4294967295 32) ?x64100)))
(let ((?x63772 (bvmul arg0_12 arg1_37)))
(let ((?x75523 (bvadd ?x63772 ?x69262)))
(and (distinct ?x75523 (_ bv0 32)) true))))))
(check-sat)
