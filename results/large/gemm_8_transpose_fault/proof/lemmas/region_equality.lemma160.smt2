; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_53 () (_ BitVec 32))
(declare-fun arg0_21 () (_ BitVec 32))
(declare-fun arg1_46 () (_ BitVec 32))
(assert
 (let ((?x72920 (bvmul arg0_21 arg1_53)))
(let ((?x62409 (bvmul (_ bv4294967295 32) ?x72920)))
(let ((?x649 (bvmul arg0_21 arg1_46)))
(let ((?x55962 (bvadd ?x649 ?x62409)))
(and (distinct ?x55962 (_ bv0 32)) true))))))
(check-sat)
